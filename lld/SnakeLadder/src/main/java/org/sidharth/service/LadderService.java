package org.sidharth.service;

import org.sidharth.model.Ladder;
import org.sidharth.repository.LadderRepository;

import java.util.Map;
import java.util.Scanner;

public class LadderService {

    public static Boolean isLadderPresent(int pos) {
        return LadderRepository.getLaddersMap().containsKey(pos);
    }

    public static Integer climbUpLadder(int pos) {
        return LadderRepository.getLaddersMap().get(pos).getTop();
    }

    public static void initializeSnakeRepository() {
        Map<Integer, Ladder> laddersMap = LadderRepository.getLaddersMap();

        Scanner scanner = new Scanner(System.in);
        int numLadders = scanner.nextInt();

        while (numLadders > 0) {
            int bottom = scanner.nextInt();
            int top = scanner.nextInt();
            laddersMap.put(bottom, new Ladder(top, bottom));
            numLadders--;
        }
    }
}
