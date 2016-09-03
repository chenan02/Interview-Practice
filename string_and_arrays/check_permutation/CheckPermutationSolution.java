// Use an array of all ASCII and index that
import java.util.*;

public class CheckPermutationSolution {
  public static boolean checkpp(String l, String r) {
    // CHECK FIRST! Early return.
    if(l.length() != r.length()) {
      return false;
    }
    // Use array the size of alphabet instead of hashmap
    int[] alphabet = new int[128];
    for(int i = 0; i < l.length(); i++) {
      alphabet[l.charAt(i)]++;
    }
    for(int i = 0; i < r.length(); i++) {
      alphabet[r.charAt(i)]--;
      if(alphabet[r.charAt(i)] < 0) {
        return false;
      }
    }
    return true;
  }

  public static void main(String[] args) {
    String result = checkpp("hello", "lehol") ? "yes" : "no";
    System.out.println(result);
    result = checkpp("saf", "fadf") ? "yes" : "no";
    System.out.println(result);
  }
}
