// Runtime: 20 ms (Top 63.84%) | Memory: 50.7 MB (Top 74.53%)
class Solution {
  public List<String> invalidTransactions(String[] transactions) {
    Map<String, List<Transaction>> nameToTransaction = new HashMap<>();
    for (int i = 0; i < transactions.length; i++) {
      Transaction t = new Transaction(transactions[i], i);
      nameToTransaction.putIfAbsent(t.name, new ArrayList<>());
      nameToTransaction.get(t.name).add(t);
    }
    List<String> invalid = new ArrayList<>();
    for (List<Transaction> list : nameToTransaction.values()) {
      for (Transaction t : list) {
        if (t.isInvalidAmount()) invalid.add(transactions[t.id]);
        else {
          for (Transaction otherT : list) {
            if (t.isInvalidCity(otherT)) {
              invalid.add(transactions[t.id]);
              break;
            }
          }
        }
      }
    }
    return invalid;
  }
}

class Transaction {
  String name, city;
  int time, amount, id;

  Transaction(String s, int id) {
    this.id = id;
    String[] split = s.split(",");
    name = split[0];
    time = Integer.parseInt(split[1]);
    amount = Integer.parseInt(split[2]);
    city = split[3];
  }

  boolean isInvalidAmount() {
    return this.amount > 1000;
  }

  boolean isInvalidCity(Transaction t) {
    return !city.equals(t.city) && Math.abs(t.time - time) <= 60;
  }
}