package org.sidharth;

import org.sidharth.model.Board;
import org.sidharth.service.GameService;

public class Main {
    public static void main(String[] args) {
        GameService gameService = new GameService(new Board(100));
        gameService.startGame();
    }
}