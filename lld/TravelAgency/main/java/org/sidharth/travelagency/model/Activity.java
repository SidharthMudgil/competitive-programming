package org.sidharth.travelagency.model;


import java.util.Objects;

public final class Activity {
    private final String name;
    private final String description;
    private final double cost;
    private final int capacity;
    private int filledCapacity = 0;


    public Activity(String name, String description, double cost, int capacity) {
        this.name = name;
        this.description = description;
        this.cost = cost;
        this.capacity = capacity;
    }

    public String details() {
        return "name = " + name + "\n" +
                "description = " + description + "\n" +
                "cost = " + cost + "\n" +
                "capacity = " + capacity;
    }

    public String name() {
        return name;
    }

    public String description() {
        return description;
    }

    public double cost() {
        return cost;
    }

    public int capacity() {
        return capacity;
    }

    public int spaceLeft() {
        return capacity - filledCapacity;
    }

    public void addPassenger() {
        filledCapacity++;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj == null || obj.getClass() != this.getClass()) return false;
        var that = (Activity) obj;
        return Objects.equals(this.name, that.name) &&
                Objects.equals(this.description, that.description) &&
                Double.doubleToLongBits(this.cost) == Double.doubleToLongBits(that.cost) &&
                this.capacity == that.capacity;
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, description, cost, capacity);
    }

    @Override
    public String toString() {
        return "Activity[" +
                "name=" + name + ", " +
                "description=" + description + ", " +
                "cost=" + cost + ", " +
                "capacity=" + capacity + ']';
    }

}
