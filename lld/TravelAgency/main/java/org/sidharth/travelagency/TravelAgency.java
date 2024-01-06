package org.sidharth.travelagency;

import org.sidharth.travelagency.domain.enums.PassengerType;
import org.sidharth.travelagency.model.Activity;
import org.sidharth.travelagency.model.Destination;
import org.sidharth.travelagency.model.Passenger;
import org.sidharth.travelagency.model.TravelPackage;
import org.sidharth.travelagency.service.TravelService;

import java.util.ArrayList;
import java.util.List;

public class TravelAgency {
    public static void main(String[] args) {
        Activity activity1 = new Activity("Sightseeing", "Explore the city", 50.0, 20);
        Activity activity2 = new Activity("Hiking", "Enjoy the nature trails", 30.0, 15);
        Activity activity3 = new Activity("Cruise", "Boat tour", 80.0, 25);

        Destination destination1 = new Destination("City A", new ArrayList<>(List.of(activity1, activity2)));
        Destination destination2 = new Destination("City B", new ArrayList<>(List.of(activity3)));

        TravelPackage package1 = new TravelPackage("Package 1", 30, new ArrayList<>(List.of(destination1, destination2)), new ArrayList<>());

        Passenger standardPassenger = new Passenger(1, "John", PassengerType.STANDARD, 200.0, new ArrayList<>());
        Passenger goldPassenger = new Passenger(2, "Alice", PassengerType.GOLD, 300.0, new ArrayList<>());
        Passenger premiumPassenger = new Passenger(3, "Bob", PassengerType.PREMIUM, 0.0, new ArrayList<>());

        TravelService travelService = new TravelService();
        travelService.addTravelPackage(package1);

        travelService.addPassengerToTravelPackage(package1, standardPassenger, new ArrayList<>(List.of(activity1, activity2)));
        travelService.addPassengerToTravelPackage(package1, goldPassenger, new ArrayList<>(List.of(activity3)));
        travelService.addPassengerToTravelPackage(package1, premiumPassenger, new ArrayList<>(List.of(activity1, activity2, activity3)));

        travelService.printTravelPackageItinerary("Package 1");
        travelService.printTravelPackagePassengers("Package 1");

        travelService.printPassengerDetails(1);
        travelService.printPassengerDetails(2);
        travelService.printPassengerDetails(3);

        travelService.printAvailableActivities();
    }
}