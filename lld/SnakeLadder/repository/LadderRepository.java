package org.sidharth.repository;

import org.sidharth.model.Ladder;

import java.util.HashMap;
import java.util.Map;

public class LadderRepository {

    private static final Map<Integer, Ladder> laddersMap = new HashMap<>();

    public static Map<Integer, Ladder> getLaddersMap() {
        return laddersMap;
    }
}
