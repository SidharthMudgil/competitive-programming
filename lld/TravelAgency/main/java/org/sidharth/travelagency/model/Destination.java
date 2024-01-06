package org.sidharth.travelagency.model;

import java.util.ArrayList;

public record Destination(
        String name,
        ArrayList<Activity> activities
) {
}