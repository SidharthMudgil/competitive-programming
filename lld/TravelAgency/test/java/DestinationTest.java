import org.junit.Test;
import org.sidharth.travelagency.model.Destination;

import java.util.ArrayList;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

public class DestinationTest {
    @Test
    public void destinationInitializationTest() {
        Destination destination = new Destination("City A", new ArrayList<>());
        assertEquals("City A", destination.name());
        assertTrue(destination.activities().isEmpty());
    }
}
