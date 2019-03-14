package listeners;

import org.testng.ISuite;
import org.testng.ISuiteListener;

public class ListenetSuite implements ISuiteListener {
    @Override
    public void onStart(ISuite iSuite) {
        System.out.printf("Starting tests on group(s): %s%n", iSuite.getName());
    }

    @Override
    public void onFinish(ISuite iSuite) {

    }
}
