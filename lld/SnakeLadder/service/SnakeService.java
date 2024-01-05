package org.sidharth.service;

import org.sidharth.model.Snake;
import org.sidharth.repository.SnakeRepository;

import java.util.Map;
import java.util.Scanner;

public class SnakeService {

    public static Boolean isSnakePresent(int pos) {
        return SnakeRepository.getSnakesMap().containsKey(pos);
    }

    public static Integer goToSnakeTail(int pos) {
        return SnakeRepository.getSnakesMap().get(pos).getTail();
    }

    public static void initializeSnakeRepository() {
        Map<Integer, Snake> snakesMap = SnakeRepository.getSnakesMap();

        Scanner scanner = new Scanner(System.in);
        int numSnakes = scanner.nextInt();

        while (numSnakes > 0) {
            int head = scanner.nextInt();
            int tail = scanner.nextInt();
            snakesMap.put(head, new Snake(head, tail));
            numSnakes--;
        }
    }
}
