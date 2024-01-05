package org.sidharth.service;

import java.util.Random;
import java.util.Scanner;

public class DiceService {
    private static int numDices = 1;
    public static int rollDice() {
        return new Random().nextInt(numDices * 6 - numDices) + numDices;
    }

    public static void initializeDiceService() {
        Scanner scanner = new Scanner(System.in);
        numDices = scanner.nextInt();
    }
}
