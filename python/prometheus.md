# Instrumenting Python with Prometheus
-Install: `pip install prometheus_client`

Next you have to decide where to start instrumenting. A good way to start is to find a natual choke point such as a requerst router which most execution will pass through.

```python
HANDLERS = {'/foo': some_function, '/bar': other_function}

def route_request(request):
    HANDLERS[request.path](request)
```

This is part of an online serving system, so we would like to know request rate, errors and latency:
```
from prometheus_client import Summary, Counter

HANDLERS = {'/foo': some_function, '/bar': other_function}

REQUEST_DURATION = Summary('my_router_request_latency_seconds', 'Latency of request router handlers', ['path'])
REQUEST_EXCEPTIONS = Counter（‘my_router_request_exceptions_total', 'Exceptions thrown in request router handlers', ['path'])

def route_request(request):
  with REQUEST_DURATION.labels(request.path).time():
    with REQST_EXCEPTIONS.labels(request.path).count_exceptions()
      HANDLERS[request.path](request)
```
This creates a summary to track the latency, and a counter to track exceptions. The summary will include the number of requsts, so you don't technically have to have a separate Counter for that in order to calculate exception ratio.

This is all split out by a label on path, so to ensure we are exporting time series for all path even before they are first used we should initialise them:
```python
for k in HANDLERS.keys():
    REQUEST_DURATION.labels(k)
    REQUEST_EXCEPTIONS.labels(k)
```
Instrumentation like this can be added throughout your codebase.

