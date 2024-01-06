import org.junit.Test;
import org.sidharth.travelagency.model.Activity;

import static org.junit.Assert.assertEquals;

public class ActivityTest {

    @Test
    public void activityInitializationTest() {
        Activity activity = new Activity("Sightseeing", "Explore the city", 50.0, 20);
        assertEquals("Sightseeing", activity.name());
        assertEquals("Explore the city", activity.description());
        assertEquals(50.0, activity.cost(), 0.0);
        assertEquals(20, activity.capacity());
    }
}
