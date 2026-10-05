public class Karakter {
    // =========================
    // ATTRIBUTE
    // =========================

    // ID digunakan sebagai identitas unik untuk setiap karakter.
    protected String id;

    // Nama menyimpan nama karakter dalam game.
    protected String nama;

    // Level menunjukkan tingkat perkembangan karakter.
    protected int level;

    // HP menunjukkan jumlah health point karakter saat ini.
    protected int hp;

    // Max HP menunjukkan batas maksimum health point karakter.
    protected int max_hp;

    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor kosong.
    // Nilai awal diberikan agar seluruh atribut terinisialisasi.
    public Karakter() {
        this("", "", 0, 0, 0);
    }

    // Constructor berparameter untuk mengisi seluruh atribut dasar Karakter.
    public Karakter(String id, String nama, int level, int hp, int max_hp) {
        this.id = id;
        this.nama = nama;
        this.level = level;
        this.hp = hp;
        this.max_hp = max_hp;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter id digunakan untuk mengubah ID karakter.
    public void setId(String id) {
        this.id = id;
    }

    // Getter id digunakan untuk mengambil ID karakter.
    public String getId() {
        return id;
    }

    // Setter nama digunakan untuk mengubah nama karakter.
    public void setNama(String nama) {
        this.nama = nama;
    }

    // Getter nama digunakan untuk mengambil nama karakter.
    public String getNama() {
        return nama;
    }

    // Setter level digunakan untuk mengubah level karakter.
    // Level tidak boleh bernilai negatif.
    public void setLevel(int level) {
        if (level >= 0) {
            this.level = level;
        } else {
            System.out.println("Error: level tidak boleh negatif.");
        }
    }

    // Getter level digunakan untuk mengambil level karakter.
    public int getLevel() {
        return level;
    }

    // Setter hp digunakan untuk mengubah health point karakter.
    // HP harus berada di antara 0 dan max_hp.
    public void setHp(int hp) {
        if (hp >= 0 && hp <= max_hp) {
            this.hp = hp;
        } else if (hp < 0) {
            System.out.println("Error: HP tidak boleh negatif.");
        } else {
            System.out.println("Error: HP tidak boleh melebihi max HP.");
        }
    }

    // Getter hp digunakan untuk mengambil health point karakter.
    public int getHp() {
        return hp;
    }

    // Setter max HP digunakan untuk mengubah batas maksimum HP.
    // Max HP harus lebih dari 0 dan tidak boleh lebih kecil dari HP saat ini.
    public void setMaxHp(int max_hp) {
        if (max_hp > 0 && max_hp >= hp) {
            this.max_hp = max_hp;
        } else if (max_hp <= 0) {
            System.out.println("Error: max HP harus lebih dari 0.");
        } else {
            System.out.println("Error: max HP tidak boleh lebih kecil dari HP saat ini.");
        }
    }

    // Getter max HP digunakan untuk mengambil batas maksimum HP.
    public int getMaxHp() {
        return max_hp;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Menampilkan seluruh informasi dasar Karakter.
    // Method ini dapat digunakan oleh object Karakter maupun class turunannya.
    public void tampilkan_info() {
        System.out.println("ID              : " + id);
        System.out.println("Nama            : " + nama);
        System.out.println("Level           : " + level);
        System.out.println("HP              : " + hp + "/" + max_hp);
    }
}