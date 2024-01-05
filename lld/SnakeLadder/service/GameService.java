package org.sidharth.service;

import org.sidharth.model.Board;
import org.sidharth.model.Player;
import org.sidharth.repository.PlayerRepository;


public class GameService {

    private final Board board;

    public GameService(Board board) {
        this.board = board;
        DiceService.initializeDiceService();
        PlayerService.initializePlayerRepository();
        LadderService.initializeSnakeRepository();
        SnakeService.initializeSnakeRepository();
    }

    public void startGame() {
        while (true) {
            for (Player player: PlayerRepository.getPlayerMap().values()) {
                System.out.println(player.getName() + ": " + player.getPos());
            }
            for (String player: PlayerRepository.getPlayerMap().keySet()) {
                int newPos = movePlayer(player);
                if (newPos == board.getEnd()) {
                    System.out.println(player + " won");
                    return;
                }
            }
            System.out.println();
        }
    }

    private int movePlayer(String playerName) {
        Player player = PlayerRepository.getPlayerMap().get(playerName);

        int diceRollValue = DiceService.rollDice();
        int currPlayerPos = player.getPos();
        int newPlayerPos = currPlayerPos + diceRollValue;

        if (newPlayerPos <= board.getEnd()) {
            currPlayerPos = newPlayerPos;
            System.out.println(playerName + " rolled " + diceRollValue + " and moved to " + currPlayerPos);
        }

        if (SnakeService.isSnakePresent(currPlayerPos)) {
            currPlayerPos = SnakeService.goToSnakeTail(currPlayerPos);
            System.out.println(playerName + " rolled " + diceRollValue + " and eaten by snake to " + currPlayerPos);
        }

        if (LadderService.isLadderPresent(currPlayerPos)) {
            currPlayerPos = LadderService.climbUpLadder(currPlayerPos);
            System.out.println(playerName + " rolled " + diceRollValue + " and climb up the ladder to " + currPlayerPos);
        }

        player.setPos(currPlayerPos);
        return currPlayerPos;
    }
}
