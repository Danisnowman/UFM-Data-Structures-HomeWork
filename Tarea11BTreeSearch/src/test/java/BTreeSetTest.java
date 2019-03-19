import static org.testng.Assert.*;

import org.testng.Assert;
import org.testng.annotations.DataProvider;
import org.testng.annotations.Test;

public class BTreeSetTest {
    @Test(groups = "All")
    public void add(){
        BTreeSet<String> bts = new BTreeSet<>(5);
        bts.add("test");
        Assert.assertTrue(bts.contains("test"));
    }

    @Test(groups = "All")
    public void contains(){
        BTreeSet<String> bts = new BTreeSet<>(5);
        for (int i = 0; i < 100 ; i++) {
            bts.add(String.valueOf(i));
            Assert.assertTrue(bts.contains(String.valueOf(i)));
        }
    }

    @Test(groups = "All")
    public void containsInvalid(){
        BTreeSet<String> bts = new BTreeSet<>(5);
        for (int i = 0; i < 100 ; i++) {
            bts.add(String.valueOf(i));
            Assert.assertFalse(bts.contains(String.valueOf((i+2)^25519)));
        }
    }
}
