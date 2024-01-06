package org.sidharth.travelagency.service;

import org.sidharth.travelagency.domain.enums.PassengerType;
import org.sidharth.travelagency.model.Activity;
import org.sidharth.travelagency.model.Destination;
import org.sidharth.travelagency.model.Passenger;
import org.sidharth.travelagency.model.TravelPackage;

import java.util.HashMap;
import java.util.List;

public class TravelService {

    private final HashMap<String, TravelPackage> travelPackageMap;

    public TravelService() {
        this.travelPackageMap = new HashMap<>();
    }

    public void addTravelPackage(TravelPackage travelPackage) {
        travelPackageMap.put(travelPackage.name(), travelPackage);
    }

    public void addPassengerToTravelPackage(TravelPackage travelPackage, Passenger passenger, List<Activity> activities) {
        if (travelPackage.seatsLeft() > 0) {
            travelPackage.addPassenger(passenger);
            for (Activity activity: activities) {
                if (activity.spaceLeft() > 0 && passenger.hasSufficientBalance(activity.cost())) {
                    passenger.deductBalance(activity.cost());
                    passenger.signedActivities().add(activity);
                    activity.addPassenger();
                } else {
                    System.out.println("Unable to add passenger to " + activity.name() +  ". Insufficient capacity or balance.");
                }
            }
        } else {
            System.out.println("Unable to add passenger to travel package. Passenger capacity reached.");
        }
    }

    public void printTravelPackageItinerary(String packageName) {
        TravelPackage travelPackage = travelPackageMap.get(packageName);
        if (travelPackage != null) {
            travelPackage.showItinerary();
        } else {
            System.out.println("Travel package not found: " + packageName);
        }
    }

    public void printTravelPackagePassengers(String packageName) {
        TravelPackage travelPackage = travelPackageMap.get(packageName);
        if (travelPackage != null) {
            travelPackage.showPassengers();
        } else {
            System.out.println("Travel package not found: " + packageName);
        }
    }

    public void printPassengerDetails(int passengerNo) {
        for (TravelPackage travelPackage : travelPackageMap.values()) {
            List<Passenger> matchingPassengers = travelPackage
                    .passengers()
                    .stream()
                    .filter(passenger -> passenger.passengerNo() == passengerNo)
                    .toList();

            if (!matchingPassengers.isEmpty()) {
                Passenger passenger = matchingPassengers.get(0);
                printPassengerDetails(passenger);
                return;
            }
        }
        System.out.println("Passenger not found: " + passengerNo);
    }

    private void printPassengerDetails(Passenger passenger) {
        System.out.println("Passenger Details:");
        System.out.println("Name: " + passenger.name());
        System.out.println("Passenger Number: " + passenger.passengerNo());
        if (passenger.passengerType() != PassengerType.PREMIUM) {
            System.out.println("Balance: " + passenger.balance());
        }
        System.out.println("Signed Activities:");
        for (Activity activity : passenger.signedActivities()) {
            System.out.println("Activity = " + activity.name());

            Destination destination = findDestinationByActivity(activity);
            if (destination != null) {
                System.out.println("Destination = " + destination.name());
                System.out.println("Price Paid = " + passenger.getOffValue(activity.cost()));
            }
        }
    }

    private Destination findDestinationByActivity(Activity activity) {
        for (TravelPackage travelPackage : travelPackageMap.values()) {
            for (Destination destination : travelPackage.itinerary()) {
                if (destination.activities().contains(activity)) {
                    return destination;
                }
            }
        }
        return null;
    }

    public void printAvailableActivities() {
        for (TravelPackage travelPackage : travelPackageMap.values()) {
            for (Destination destination : travelPackage.itinerary()) {
                for (Activity activity : destination.activities()) {
                    System.out.println("Activity: " + activity.name());
                    System.out.println("Destination = " + destination.name());
                    System.out.println("Space left = " + activity.spaceLeft());
                }
            }
        }
    }

    public HashMap<String, TravelPackage> getTravelPackageMap() {
        return travelPackageMap;
    }
}