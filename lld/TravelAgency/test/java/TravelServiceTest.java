import org.junit.Test;
import org.sidharth.travelagency.domain.enums.PassengerType;
import org.sidharth.travelagency.model.Activity;
import org.sidharth.travelagency.model.Passenger;
import org.sidharth.travelagency.model.TravelPackage;
import org.sidharth.travelagency.service.TravelService;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class TravelServiceTest {
    @Test
    public void travelServiceInitializationTest() {
        TravelService travelService = new TravelService();
        assertNotNull(travelService);
    }

    @Test
    public void addTravelPackageTest() {
        TravelService travelService = new TravelService();
        TravelPackage travelPackage = new TravelPackage("Package 1", 30, new ArrayList<>(), new ArrayList<>());
        travelService.addTravelPackage(travelPackage);
        assertTrue(travelService.getTravelPackageMap().containsKey("Package 1"));
    }

    @Test
    public void addPassengerToTravelPackage_ExceedPassengerCapacity() {
        TravelService travelService = new TravelService();
        TravelPackage travelPackage = new TravelPackage("Package 1", 1, new ArrayList<>(), new ArrayList<>());
        travelService.addTravelPackage(travelPackage);

        Passenger passenger1 = new Passenger(1, "John", PassengerType.STANDARD, 200.0, new ArrayList<>());
        travelService.addPassengerToTravelPackage(travelPackage, passenger1, new ArrayList<>());
        assertEquals(1, travelPackage.passengers().size());

        Passenger passenger2 = new Passenger(2, "Alice", PassengerType.GOLD, 300.0, new ArrayList<>());
        travelService.addPassengerToTravelPackage(travelPackage, passenger2, new ArrayList<>());
        assertEquals(0, passenger2.signedActivities().size());
    }

    @Test
    public void addPassengerToTravelPackage_ExceedActivityCapacity() {
        TravelService travelService = new TravelService();
        TravelPackage travelPackage = new TravelPackage("Package 1", 2, new ArrayList<>(), new ArrayList<>());
        travelService.addTravelPackage(travelPackage);

        Activity activity = new Activity("Sightseeing", "Explore the city", 50.0, 1);

        Passenger passenger1 = new Passenger(1, "John", PassengerType.STANDARD, 200.0, new ArrayList<>());
        travelService.addPassengerToTravelPackage(travelPackage, passenger1, List.of(activity));
        assertEquals(1, travelPackage.passengers().size());

        Passenger passenger2 = new Passenger(2, "Alice", PassengerType.GOLD, 300.0, new ArrayList<>());
        travelService.addPassengerToTravelPackage(travelPackage, passenger2, List.of(activity));
        assertEquals(0, passenger2.signedActivities().size());

        assertEquals(0, activity.spaceLeft());
    }

    @Test
    public void addPassengerToTravelPackage_InsufficientBalance() {
        TravelService travelService = new TravelService();
        TravelPackage travelPackage = new TravelPackage("Package 1", 2, new ArrayList<>(), new ArrayList<>());
        travelService.addTravelPackage(travelPackage);

        Activity activity1 = new Activity("Sightseeing", "Explore the city", 50.0, 1);
        Activity activity2 = new Activity("Hiking", "Enjoy nature", 40.0, 1);

        Passenger passenger = new Passenger(1, "John", PassengerType.STANDARD, 30.0, new ArrayList<>());

        travelService.addPassengerToTravelPackage(travelPackage, passenger, List.of(activity1, activity2));
        assertEquals(1, activity1.spaceLeft());
        assertEquals(1, activity2.spaceLeft());
        assertEquals(0, passenger.signedActivities().size());
        assertEquals(1, travelPackage.passengers().size());

    }
}
