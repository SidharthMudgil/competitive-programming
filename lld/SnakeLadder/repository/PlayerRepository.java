package org.sidharth.repository;

import org.sidharth.model.Player;

import java.util.HashMap;
import java.util.Map;

public class PlayerRepository {

    private static final Map<String, Player> playerMap = new HashMap<>();

    public static Map<String, Player> getPlayerMap() {
        return playerMap;
    }
}
