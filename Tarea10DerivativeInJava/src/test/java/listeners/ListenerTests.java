package listeners;
import org.testng.*;

import java.util.Arrays;

public class ListenerTests implements ITestListener{
    public void onTestStart(ITestResult iTestResult) {

    }

    public void onTestSuccess(ITestResult iTestResult) {
        String method_name = iTestResult.getMethod().getDescription();
        System.out.println("Succeeded method: " + method_name);

    }

    public void onTestFailure(ITestResult iTestResult) {
        String method_name = iTestResult.getMethod().getDescription();
        System.out.println("Failed method: " + method_name);
    }

    public void onTestSkipped(ITestResult iTestResult) {
        String method_name = iTestResult.getMethod().getDescription();
        System.out.println("Skipped method: " + method_name);
    }

    public void onTestFailedButWithinSuccessPercentage(ITestResult iTestResult) {

    }

    public void onStart(ITestContext iTestContext) {
        System.out.println("Starting tests on group(s): " + Arrays.toString(iTestContext.getIncludedGroups()));

    }

    public void onFinish(ITestContext iTestContext) {

    }
}
