public class Player extends Karakter {
    // =========================
    // ATTRIBUTE
    // =========================

    // Experience point menunjukkan jumlah pengalaman yang telah diperoleh Player.
    private int exp;

    // Gold menunjukkan jumlah mata uang yang dimiliki Player.
    private int gold;

    // Inventory merupakan bagian dari Player untuk menyimpan dan mengelola item.
    // Hubungan Player dengan Inventory merupakan composition.
    private Inventory inventory;

    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor tanpa parameter.
    // Inventory dibuat sebagai bagian dari object Player (composition).
    public Player() {
        this.inventory = new Inventory();
    }

    // Constructor berparameter.
    // Constructor parent Karakter dipanggil untuk menginisialisasi atribut dasar.
    // Inventory dibuat sebagai bagian dari object Player.
    public Player(String id, String nama, int level, int hp, int max_hp, int exp, int gold) {
        super(id, nama, level, hp, max_hp);
        this.exp = exp;
        this.gold = gold;
        this.inventory = new Inventory();
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter exp digunakan untuk mengubah experience point Player.
    // Experience tidak boleh bernilai negatif.
    public void setExp(int exp) {
        if (exp >= 0) {
            this.exp = exp;
        } else {
            System.out.println("Error: experience point tidak boleh negatif.");
        }
    }

    // Getter exp digunakan untuk mengambil experience point Player.
    public int getExp() {
        return exp;
    }

    // Setter gold digunakan untuk mengubah jumlah gold Player.
    // Gold tidak boleh bernilai negatif.
    public void setGold(int gold) {
        if (gold >= 0) {
            this.gold = gold;
        } else {
            System.out.println("Error: gold tidak boleh negatif.");
        }
    }

    // Getter gold digunakan untuk mengambil jumlah gold Player.
    public int getGold() {
        return gold;
    }

    // Getter inventory mengembalikan Inventory agar dapat diakses dan dimodifikasi.
    // Java tidak memiliki overload method const seperti pada C++.
    public Inventory getInventory() {
        return inventory;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Menampilkan seluruh informasi Player.
    // Informasi dasar karakter berasal dari class Karakter melalui inheritance.
    public void tampilkan_info() {
        super.tampilkan_info();
        System.out.println("EXP             : " + exp);
        System.out.println("Gold            : " + gold);
    }
}
