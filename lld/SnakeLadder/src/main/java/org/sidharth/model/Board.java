package org.sidharth.model;

public class Board {
    private final int size;
    private final int start;
    private final int end;

    public Board() {
        this.size = 100;
        this.start = 0;
        this.end = 100;
    }

    public Board(int size) {
        this.size = size;
        this.start = 0;
        this.end = size;
    }

    public Board(int size, int start, int end) {
        this.size = size;
        this.start = start;
        this.end = end;
    }

    public int getSize() {
        return size;
    }

    public int getStart() {
        return start;
    }

    public int getEnd() {
        return end;
    }
}
