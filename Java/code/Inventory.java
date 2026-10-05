import java.util.ArrayList;
import java.util.List;

public class Inventory {
    // =========================
    // ATTRIBUTE
    // =========================

    // Kapasitas maksimal menunjukkan jumlah slot maksimum Inventory.
    private int kapasitas_maksimal;

    // Daftar item menyimpan kumpulan object Item milik Inventory.
    // Item disimpan langsung di dalam Inventory sebagai composition.
    private List<Item> daftar_item;

    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor tanpa parameter.
    // Daftar item dibuat kosong dan kapasitas awal bernilai 0.
    public Inventory() {
        this.kapasitas_maksimal = 0;
        this.daftar_item = new ArrayList<>();
    }

    // Constructor berparameter untuk menentukan kapasitas maksimal Inventory.
    public Inventory(int kapasitas_maksimal) {
        this.kapasitas_maksimal = kapasitas_maksimal;
        this.daftar_item = new ArrayList<>();
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter kapasitas maksimal digunakan untuk mengubah kapasitas Inventory.
    // Kapasitas tidak boleh lebih kecil dari jumlah item yang sudah tersimpan.
    public void setKapasitasMaksimal(int kapasitas_maksimal) {
        if (kapasitas_maksimal < 0) {
            System.out.println("Error: kapasitas tidak boleh negatif.");
        } else if (kapasitas_maksimal < daftar_item.size()) {
            System.out.println("Error: kapasitas tidak boleh lebih kecil dari jumlah item saat ini.");
        } else {
            this.kapasitas_maksimal = kapasitas_maksimal;
        }
    }

    // Getter kapasitas maksimal digunakan untuk mengambil kapasitas Inventory.
    public int getKapasitasMaksimal() {
        return kapasitas_maksimal;
    }

    // Getter daftar item mengembalikan salinan daftar item Inventory.
    public List<Item> getDaftarItem() {
        return new ArrayList<>(daftar_item);
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Menambahkan object Item jika Inventory masih memiliki slot kosong.
    public void tambahItem(Item item) {
        if (daftar_item.size() < kapasitas_maksimal) {
            daftar_item.add(item);
        } else {
            System.out.println("Error: Inventory sudah penuh.");
        }
    }

    // Menampilkan kapasitas dan seluruh Item yang tersimpan di dalam Inventory.
    public void tampilkan_info() {
        System.out.println("Kapasitas       : " + daftar_item.size() + "/" + kapasitas_maksimal);
        System.out.println("Daftar Item:");

        if (daftar_item.isEmpty()) {
            System.out.println("  Inventory kosong.");
        } else {
            // Menampilkan informasi setiap Item yang tersimpan.
            for (int i = 0; i < daftar_item.size(); i++) {
                Item item = daftar_item.get(i);

                System.out.println();
                System.out.println("  Item ke-" + (i + 1));
                System.out.println("  ID Item       : " + item.getIdItem());
                System.out.println("  Nama Item     : " + item.getNamaItem());
                System.out.println("  Tipe Item     : " + item.getTipeItem());
                System.out.println("  Berat         : " + item.getBerat() + " kg");
                System.out.println("  Harga Jual    : Rp" + item.getHargaJual());
                System.out.println("  Quantity      : " + item.getQuantity());
            }
        }
    }
}