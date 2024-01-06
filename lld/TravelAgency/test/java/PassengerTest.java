import org.junit.Test;
import org.sidharth.travelagency.domain.enums.PassengerType;
import org.sidharth.travelagency.model.Passenger;

import java.util.ArrayList;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

public class PassengerTest {
    @Test
    public void passengerInitializationTest() {
        Passenger passenger = new Passenger(1, "John", PassengerType.STANDARD, 200.0, new ArrayList<>());
        assertEquals(1, passenger.passengerNo());
        assertEquals("John", passenger.name());
        assertEquals(PassengerType.STANDARD, passenger.passengerType());
        assertEquals(200.0, passenger.balance(), 0.0);
        assertTrue(passenger.signedActivities().isEmpty());
    }

    @Test
    public void deductBalanceTest() {
        Passenger passenger = new Passenger(1, "John", PassengerType.STANDARD, 200.0, new ArrayList<>());
        passenger.deductBalance(50.0);
        assertEquals(150.0, passenger.balance(), 0.0);
    }
}

