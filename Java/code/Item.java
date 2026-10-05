public class Item {
    // =========================
    // ATTRIBUTE
    // =========================

    // ID item digunakan sebagai identitas unik untuk setiap Item.
    private String id_item;

    // Nama item menyimpan nama barang dalam game.
    private String nama_item;

    // Tipe item menunjukkan kategori item.
    private String tipe_item;

    // Berat menunjukkan berat satu Item dalam satuan kilogram.
    private float berat;

    // Harga jual menunjukkan nilai Item ketika dijual.
    private int harga_jual;

    // Quantity menunjukkan jumlah Item sejenis dalam satu slot Inventory.
    private int quantity;

    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor tanpa parameter.
    // Nilai default diberikan agar seluruh atribut terinisialisasi.
    public Item() {
        this.id_item = "";
        this.nama_item = "";
        this.tipe_item = "";
        this.berat = 0.0f;
        this.harga_jual = 0;
        this.quantity = 0;
    }

    // Constructor berparameter untuk mengisi seluruh atribut Item.
    public Item(String id_item, String nama_item, String tipe_item, float berat, int harga_jual, int quantity) {
        this.id_item = id_item;
        this.nama_item = nama_item;
        this.tipe_item = tipe_item;
        this.berat = berat;
        this.harga_jual = harga_jual;
        this.quantity = quantity;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter id item digunakan untuk mengubah ID Item.
    public void setIdItem(String id_item) {
        this.id_item = id_item;
    }

    // Getter id item digunakan untuk mengambil ID Item.
    public String getIdItem() {
        return id_item;
    }

    // Setter nama item digunakan untuk mengubah nama Item.
    public void setNamaItem(String nama_item) {
        this.nama_item = nama_item;
    }

    // Getter nama item digunakan untuk mengambil nama Item.
    public String getNamaItem() {
        return nama_item;
    }

    // Setter tipe item digunakan untuk mengubah kategori Item.
    public void setTipeItem(String tipe_item) {
        this.tipe_item = tipe_item;
    }

    // Getter tipe item digunakan untuk mengambil kategori Item.
    public String getTipeItem() {
        return tipe_item;
    }

    // Setter berat digunakan untuk mengubah berat Item.
    // Berat tidak boleh bernilai negatif.
    public void setBerat(float berat) {
        if (berat >= 0) {
            this.berat = berat;
        } else {
            System.out.println("Error: berat item tidak boleh negatif.");
        }
    }

    // Getter berat digunakan untuk mengambil berat Item.
    public float getBerat() {
        return berat;
    }

    // Setter harga jual digunakan untuk mengubah harga jual Item.
    // Harga jual tidak boleh bernilai negatif.
    public void setHargaJual(int harga_jual) {
        if (harga_jual >= 0) {
            this.harga_jual = harga_jual;
        } else {
            System.out.println("Error: harga jual tidak boleh negatif.");
        }
    }

    // Getter harga jual digunakan untuk mengambil harga jual Item.
    public int getHargaJual() {
        return harga_jual;
    }

    // Setter quantity digunakan untuk mengubah jumlah Item.
    // Quantity tidak boleh bernilai negatif.
    public void setQuantity(int quantity) {
        if (quantity >= 0) {
            this.quantity = quantity;
        } else {
            System.out.println("Error: quantity tidak boleh negatif.");
        }
    }

    // Getter quantity digunakan untuk mengambil jumlah Item.
    public int getQuantity() {
        return quantity;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Menampilkan seluruh informasi Item.
    public void tampilkan_info() {
        System.out.println("ID Item         : " + id_item);
        System.out.println("Nama Item       : " + nama_item);
        System.out.println("Tipe Item       : " + tipe_item);
        System.out.println("Berat           : " + berat + " kg");
        System.out.println("Harga Jual      : Rp" + harga_jual);
        System.out.println("Quantity        : " + quantity);
    }
}
