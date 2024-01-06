import org.junit.Test;
import org.sidharth.travelagency.domain.enums.PassengerType;
import org.sidharth.travelagency.model.Passenger;
import org.sidharth.travelagency.model.TravelPackage;

import java.util.ArrayList;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

public class TravelPackageTest {
    @Test
    public void travelPackageInitializationTest() {
        TravelPackage travelPackage = new TravelPackage("Package 1", 30, new ArrayList<>(), new ArrayList<>());
        assertEquals("Package 1", travelPackage.name());
        assertEquals(30, travelPackage.passengerCapacity());
        assertTrue(travelPackage.itinerary().isEmpty());
        assertTrue(travelPackage.passengers().isEmpty());
    }

    @Test
    public void addPassengerTest() {
        TravelPackage travelPackage = new TravelPackage("Package 1", 2, new ArrayList<>(), new ArrayList<>());
        Passenger passenger = new Passenger(1, "John", PassengerType.STANDARD, 200.0, new ArrayList<>());
        travelPackage.addPassenger(passenger);
        assertEquals(1, travelPackage.passengers().size());
        assertTrue(travelPackage.passengers().contains(passenger));
    }
}
