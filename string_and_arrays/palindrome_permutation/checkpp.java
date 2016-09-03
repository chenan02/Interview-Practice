/* Given a string, write a function to chekc if it is a permutation of a palindrome.
 * A palindrome is a word or pgrase that is the same forwards and backwards.
 * A permutation is a rearrangement of letters. The palindrome does not need
 * to be just dicionary word.
 *
 * Qs:
 *
 * Strategy: Use a HashMap; if it is, then there should be an even number of
 * a specific char with at most one odd
 */
import java.util.*;
import java.lang.*;

public class CheckPP {
  public static void checkpp(String s) {
    // remove whitespace
    s = s.replaceAll("\\s", "");
    HashMap<Character, Integer> map = new HashMap<Character, Integer>();
    for(int i = 0; i < s.length(); i++) {
      char c = Character.toLowerCase(s.charAt(i));
      if(map.containsKey(c)) {
        map.put(c, map.get(c) + 1);
      }
      else {
        map.put(c, 1);
      }
    }
    boolean oddFound = false;
    for(char c : map.keySet()) {
      if(map.get(c) % 2 == 1) {
        if(!oddFound) {
          oddFound = true;
        }
        else {
          System.out.println("Not permutation palindrome :(");
          return;
        }
      }
    }
    System.out.println("Permutation palindrome!!!");
  }

  public static void main(String[] args) {
    checkpp("Tact Coa");
    checkpp("sa fda a");
    checkpp("");
  }
}
