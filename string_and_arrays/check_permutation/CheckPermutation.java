import java.util.*;

public class CheckPermutation {
  public static void main(String[] args) {
    if(args.length != 2) {
      System.out.println("Please enter 2 words to compare");
      return;
    }
    HashMap<Character, Integer> hashmap = new HashMap<Character, Integer>();
    for(int i = 0; i < args[0].length(); i++) {
      char c = args[0].charAt(i);
      if(!hashmap.containsKey(c)) {
        hashmap.put(c, 1);
      }
      else {
        hashmap.put(c, hashmap.get(c) + 1);
      }
    }
    for(int i = 0; i < args[1].length(); i++) {
      char c = args[1].charAt(i);
      if(hashmap.containsKey(c)) {
        hashmap.put(c, hashmap.get(c) - 1);
      }
      else {
        System.out.println("Nope");
        return;
      }
    }
    for(char c : hashmap.keySet()) {
      if(hashmap.get(c) != 0) {
        System.out.println("Nope");
        return;
      }
    }
    System.out.println("yup");
  }
}

