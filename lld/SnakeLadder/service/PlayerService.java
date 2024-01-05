package org.sidharth.service;

import org.sidharth.model.Player;
import org.sidharth.repository.PlayerRepository;

import java.util.Map;
import java.util.Scanner;

public class PlayerService {

    public static void initializePlayerRepository() {
        Map<String, Player> playerCurrentPosition = PlayerRepository.getPlayerMap();

        Scanner scanner = new Scanner(System.in);
        int numPlayers = scanner.nextInt();

        while (numPlayers > 0) {
            String name = scanner.next();
            playerCurrentPosition.put(name, new Player(name, 0));
            numPlayers--;
        }
    }
}
