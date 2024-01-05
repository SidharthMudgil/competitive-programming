package org.sidharth.repository;

import org.sidharth.model.Snake;

import java.util.HashMap;
import java.util.Map;

public class SnakeRepository {

    private static final Map<Integer, Snake> snakesMap = new HashMap<>();

    public static Map<Integer, Snake> getSnakesMap() {
        return snakesMap;
    }
}
