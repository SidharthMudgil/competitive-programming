    package org.sidharth.travelagency.model;

    import org.sidharth.travelagency.domain.enums.PassengerType;

    import java.util.ArrayList;
    import java.util.Objects;

    public final class Passenger {
        private final int passengerNo;
        private final String name;
        private final PassengerType passengerType;
        private double balance;
        private final ArrayList<Activity> signedActivities;

        public Passenger(
                int passengerNo,
                String name,
                PassengerType passengerType,
                double balance,
                ArrayList<Activity> signedActivities
        ) {
            this.passengerNo = passengerNo;
            this.name = name;
            this.passengerType = passengerType;
            this.balance = balance;
            this.signedActivities = signedActivities;
        }

        public double getOffValue(double amount) {
            return amount - amount * passengerType.getOffPercent() / 100;
        }

        public boolean hasSufficientBalance(double amount) {
            return balance >= getOffValue(amount);
        }

        public void deductBalance(double amount) {
            balance -= getOffValue(amount);
        }

        public int passengerNo() {
            return passengerNo;
        }

        public String name() {
            return name;
        }

        public PassengerType passengerType() {
            return passengerType;
        }

        public double balance() {
            return balance;
        }

        public ArrayList<Activity> signedActivities() {
            return signedActivities;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == this) return true;
            if (obj == null || obj.getClass() != this.getClass()) return false;
            var that = (Passenger) obj;
            return this.passengerNo == that.passengerNo &&
                    Objects.equals(this.name, that.name) &&
                    Objects.equals(this.passengerType, that.passengerType) &&
                    Double.doubleToLongBits(this.balance) == Double.doubleToLongBits(that.balance) &&
                    Objects.equals(this.signedActivities, that.signedActivities);
        }

        @Override
        public int hashCode() {
            return Objects.hash(passengerNo, name, passengerType, balance, signedActivities);
        }

        @Override
        public String toString() {
            return "Passenger[" +
                    "passengerNo=" + passengerNo + ", " +
                    "name=" + name + ", " +
                    "passengerType=" + passengerType + ", " +
                    "balance=" + balance + ", " +
                    "signedActivities=" + signedActivities + ']';
        }
    }
