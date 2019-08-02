# Validate User Api
Next we will create an api to validate an existing user. Normally, if we do a get request to the user endpoint, it will give out details of all rgistered users from the database. First we need to authenticate a user using first name and password, and second we need to return the user details from the database on successful authentication.

In order to get details based on the first name, we need to add an additinal lookup field in the domain in settings.py.

```python
'additional_lookup': {
            'url': 'regex("[\w]+")',
            'field': 'username',
            }
```
As seen in the above code, we have added a look up field forusername. Now when a Get request is send to the http://127.0.0.01:5000/user/<username> it will return the details of hte user with the particular username. when making a reuqet to a particular user, we will also send the username and password for authentication.

We will be doing basic authentication to verify a particular user based on username and password. first, we need to import the Basic Authen class from EVE. Create a class called Authenticate to implement the authentiction as shown:
```python
from eve.auth import BasicAuth

class Authenticate(BasicAuth):
	def check_auth(self, username, password, allowed_roles, resource, method):
		if resource == 'user' and method == 'GET':
			user = app.data.driver.db['user']
			user = user.find_one({'username': username, 'password': password})
			if user:
				return True
			else:
				return False

		elif resource == 'user' and method == 'POST':
			return username == 'admin' and password == 'admin'
		else:
			return True
```
Now, when the resource is user and request method is get, we will authenticate the user. on successful authentication, the user details of the user with firstname in the API endopoint will be returned. We will also restrict user creation by providing a username and password. so, if the method is post and API endpoint is user, we will ceck and validate the username and password.

We need to pass the Authenticate class name while initiating the API.

## Delete Item API
#Angular JS
## Creating User Home
After the user signs in successfully, we will take the user to the home page. So, let's start by creating userHome.html. Navigate to the public folder and create a new folder called userHome. Insdie userHome create files called userHome.html and userHome.js. Open userHome.html and add the following HTML code:
```html
<div class='container'>
	<div class = 'header'>
		<nav>
			<ul class='nav nav-pills pull-right'>
				<li role='presentation' class='active'><a href='#userHome'>Home</a></li>
				<li role="presentation"><a href="#addItem">Add</a></li>
                <li role="presentation"><a href="#">Logout</a></li>
            </ul>
        </nav>
        <h3 class="text-muted">Home</h3>
    </div>
    <h1>Data will be displayed here !!</h1>
 
    <footer class="footer">
        <p>&copy; Company 2015</p>
    </footer>
</div>
```
Inside userHome.js define the module userHome and its tempalte and controller. So, open userHome.js and add the following code:
```js
'use strict';

angular.module('userHome', ['ngRoute'])

.config(['$routeProvider', function($routeProvider) {
	$routeProvider.when('/userHome', {
		templateUrl: '../userHome/userHome.html',
		controller: 'UserHomeCtrl'
		})
	}])
.controller('UserHomeCtrl', ['$scope', function($scope) {

}]);
```
Creating an Add Task Page
Let's add a view to enable the user to add items. Navigate to the public folder and create a foler clalled addItem. Inside the addItem folder, create two files called addItem.html and addItem.js. Open addItem.html and add the following HTML code:

