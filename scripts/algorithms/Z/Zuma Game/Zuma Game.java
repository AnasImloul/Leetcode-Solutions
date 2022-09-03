// Runtime: 1091 ms (Top 50.54%) | Memory: 147.1 MB (Top 58.06%)
class Solution {
    static class Hand {
        int red;
        int yellow;
        int green;
        int blue;
        int white;

        Hand(String hand) {
            // add an extra character, because .split() throws away trailing empty strings
            String splitter = hand + "x";
            red = splitter.split("R").length - 1;
            yellow = splitter.split("Y").length - 1;
            green = splitter.split("G").length - 1;
            blue = splitter.split("B").length - 1;
            white = splitter.split("W").length - 1;
        }
        Hand(Hand hand) {
            red = hand.red;
            yellow = hand.yellow;
            blue = hand.blue;
            green = hand.green;
            white = hand.white;
        }
        boolean isEmpty() {
            return red == 0 && yellow == 0 && green == 0 && blue == 0 && white == 0;
        }
        List<String> colors() {
            List<String> res = new ArrayList<>();
            if(red > 0) res.add("R");
            if(yellow > 0) res.add("Y");
            if(green > 0) res.add("G");
            if(blue > 0) res.add("B");
            if(white > 0) res.add("W");
            return res;
        }
        void removeColor(String color) {
            switch(color) {
            case "R":
                red--;
                break;
            case "Y":
                yellow--;
                break;
            case "G":
                green--;
                break;
            case "B":
                blue--;
                break;
            case "W":
                white--;
                break;
            }
        }
        public StringBuilder buildStringWithColon() {
            return new StringBuilder().append(red)
                    .append(",")
                    .append(yellow)
                    .append(",")
                    .append(green)
                    .append(",")
                    .append(blue)
                    .append(",")
                    .append(white)
                    .append(":");
        }
    }

    /** key = hand + ":" + board */
    private final Map<String, Integer> boardHandToMinStep = new HashMap<>();

    /**
     store hand in a custom object; eases work and memoization (handles equivalency of reordered hand)
     for each color in your hand:
     try to insert the color in each *effective* location
     - effective location means "one preceding a same-color set of balls"; in other words: "a location to the left of a same-color ball AND NOT to the right of a same-color ball"
     resolve the board
     if inserting to that location finishes the game, return 1
     otherwise, recur to the resulting hand
     minstep for this setup == minimum of all resulting hands + 1
     memoize this minstep, then return it
     */
    public int findMinStep(String board, String hand) {
        // store hand in a custom object; eases work and memoization (handles equivalency of reordered hand)
        Hand h = new Hand(hand);
        return findMinStep(board, h, 9999);
    }

    private int findMinStep(String board, Hand hand, int remainingDepth) {
        // resolve board, i.e. remove triples and higher
        board = resolve(board);
        final String key = hand.buildStringWithColon().append(board).toString();
        if(board.length() == 0) {
            return 0;
        } else if(boardHandToMinStep.containsKey(key)) {
            return boardHandToMinStep.get(key);
        }

        // OPTIMIZATION #3 - reduced time by 25%
        // don't go deeper than the deepest known solution - 1
        if (remainingDepth <= 0
                // OPTIMIZATION #2 - lowered from 1min to 4sec reduced time by 93%
                // for each color in the board, if there are ever fewer than three of that color in the board and hand combined, fast fail
                || !canWin(board, hand)) {
            boardHandToMinStep.put(key, -1);
            return -1;
        }

        int minStep = -1;
        // for each color in your hand:
        for(String color : hand.colors()) {
            // Store a new "next hand" and remove the color
            Hand nextHand = new Hand(hand);
            nextHand.removeColor(color);
            // for each *effective* insert location
            // - effective location means "one preceding same-color ball(s)"; in other words: "a location to the left of a same-color ball AND NOT to the right of a same-color ball"
            for(int loc : effectiveLocations(color, board, nextHand.isEmpty())) {
                // insert the color and store as "next board"
                String nextBoard = board.substring(0, loc) + color + board.substring(loc);
                // recur to the resulting hand
                int childMinStep = findMinStep(nextBoard, nextHand, minStep == -1 ? remainingDepth - 1 : minStep - 2);
                if(childMinStep != -1) {
                    // minstep for this setup == minimum of all resulting hands + 1
                    minStep = minStep == -1 ? (1 + childMinStep) : Math.min(minStep, 1 + childMinStep);
                }
            }
        }
        // memoize this minstep, then return it
        boardHandToMinStep.put(key, minStep);
        return minStep;
    }

    private boolean canWin(String board, Hand hand) {
        String splitter = board + "x";
        int red = splitter.split("R").length - 1;
        int yellow = splitter.split("Y").length - 1;
        int green = splitter.split("G").length - 1;
        int blue = splitter.split("B").length - 1;
        int white = splitter.split("W").length - 1;

        return (red == 0 || red + hand.red > 2)
        && (yellow == 0 || yellow + hand.yellow > 2)
        && (green == 0 || green + hand.green > 2)
        && (blue == 0 || blue + hand.blue > 2)
        && (white == 0 || white + hand.white > 2);
    }

    /**
     * effective location means "one preceding a same-color set of 1 or more balls"; in other words: "a location to the left of a same-color ball AND NOT to the right of a same-color ball"
     * ^^ The above first pass is incorrect. Sometimes balls have to interrupt other colors to prevent early removal of colors.
     *
     * effective location means "all locations except after a same-color ball"
     *
     */
    private List<Integer> effectiveLocations(String color, String board, boolean isLastInHand) {
        List<Integer> res = new ArrayList<>();

        // OPTIMIZATION #4 - prefer greedy locations by adding them in this order: - reduced time by 93%
        // - preceding 2 of the same color
        // - preceding exactly 1 of the same color
        // - neighboring 0 of the same color
        List<Integer> greedy2 = new ArrayList<>();
        List<Integer> greedy3 = new ArrayList<>();

        // Preceding 2 of the same color:
        for (int i = 0; i <= board.length(); i++) {
            if (i < board.length() - 1 && board.substring(i, i + 2).equals(color + color)) {
                res.add(i);
                // skip the next 2 locations; they would be part of the same consecutive set of "this" color
                i+=2;
            } else if(i < board.length() && board.substring(i,i+1).equals(color)) {
                greedy2.add(i);
                // skip the next 1 location; it would be part of the same consecutive set of "this" color
                i++;
            } else {
                // OPTIMIZATION #5 - if a ball is not next to one of the same color, it must be between two identical, of a different color - 10s to .8s
// greedy3.add(i);
                if(i > 0 && board.length() > i && board.substring(i-1, i).equals(board.substring(i, i+1))) {
                    greedy3.add(i);
                }
            }
        }
        // OPTIMIZATION #1 - reduced time by 90%
        // if this is the last one in the hand, then it MUST be added to 2 others of the same color
        if(isLastInHand) {
            return res;
        }
        res.addAll(greedy2);
        res.addAll(greedy3);
        return res;
    }

    /**
     * repeatedly collapse sets of 3 or more
     */
    private String resolve(String board) {
        String copy = "";
        while(!board.equals(copy)) {
            copy = board;
            // min 3 in a row
            board = copy.replaceFirst("(.)\\1\\1+", "");
        }
        return board;
    }
}