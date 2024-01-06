package org.sidharth.travelagency.model;

import java.util.ArrayList;
import java.util.Objects;

public final class TravelPackage {
    private final String name;
    private final int passengerCapacity;
    private final ArrayList<Destination> itinerary;
    private final ArrayList<Passenger> passengers;
    private int totalPassengers = 0;

    public TravelPackage(
            String name,
            int passengerCapacity,
            ArrayList<Destination> itinerary,
            ArrayList<Passenger> passengers
    ) {
        this.name = name;
        this.passengerCapacity = passengerCapacity;
        this.itinerary = itinerary;
        this.passengers = passengers;
    }

    public void showItinerary() {
        System.out.println("Package = " + name);
        for (Destination destination : itinerary) {
            System.out.println("Destination name = " + destination.name());

            for (Activity activity : destination.activities()) {
                System.out.println(activity.details());
            }
        }
    }

    public void showPassengers() {
        System.out.println("Package = " + name);
        System.out.println("Passenger Capacity = " + passengerCapacity);
        System.out.println("Passenger Enrolled = " + passengers.size());

        for (Passenger passenger : passengers) {
            System.out.println(passenger.passengerNo() + " " + passenger.name());
        }
    }

    public String name() {
        return name;
    }

    public int passengerCapacity() {
        return passengerCapacity;
    }

    public ArrayList<Destination> itinerary() {
        return itinerary;
    }

    public ArrayList<Passenger> passengers() {
        return passengers;
    }

    public int seatsLeft() {
        return passengerCapacity - totalPassengers;
    }

    public void addPassenger(Passenger passenger) {
        passengers.add(passenger);
        totalPassengers++;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj == null || obj.getClass() != this.getClass()) return false;
        var that = (TravelPackage) obj;
        return Objects.equals(this.name, that.name) &&
                this.passengerCapacity == that.passengerCapacity &&
                Objects.equals(this.itinerary, that.itinerary) &&
                Objects.equals(this.passengers, that.passengers);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, passengerCapacity, itinerary, passengers);
    }

    @Override
    public String toString() {
        return "TravelPackage[" +
                "name=" + name + ", " +
                "passengerCapacity=" + passengerCapacity + ", " +
                "itinerary=" + itinerary + ", " +
                "passengers=" + passengers + ']';
    }

}
