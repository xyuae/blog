package Thread;

/**
 * Created by Xiaojun YU on 2017-03-13.
 */
public class DemoThread extends Thread{

    @Override
    public void run() {
        super.run();
    }
}
/*
DemoThread t = new DemoThread();
t.start();
*/

public interface Executor {
    void execute(Runnable command)
}

