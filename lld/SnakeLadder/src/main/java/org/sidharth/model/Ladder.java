package org.sidharth.model;

public class Ladder{

    private final int top;
    private final int bottom;

    public Ladder(int top, int bottom) {
        this.top = top;
        this.bottom = bottom;
    }

    public int getTop() {
        return top;
    }

    public int getBottom() {
        return bottom;
    }
}
