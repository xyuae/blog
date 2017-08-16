package CardGame;

/**
 * Created by Xiaojun YU on 2017-08-08.
 */
public class Main {
    public static void main(String[] args) {
        Deck deck = new Deck();
        Card C;

        System.out.println(deck.getTotalCards());

        while (deck.getTotalCards() != 0) {
            C = deck.drawFromDeck();
            System.out.println(C.toString());
        }
    }
}
