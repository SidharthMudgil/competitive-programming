package org.sidharth.travelagency.domain.enums;

public enum PassengerType {
    STANDARD(0),
    GOLD(10),
    PREMIUM(100);

    private final int offPercent;

    PassengerType(int offPercent) {
        this.offPercent = offPercent;
    }

    public int getOffPercent() {
        return offPercent;
    }
}
