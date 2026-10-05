import java.util.ArrayList;
import java.util.List;

public class NPC extends Karakter {
    // =========================
    // ATTRIBUTE
    // =========================

    // Tipe NPC menunjukkan peran NPC di dalam game.
    private String tipe_npc;

    // is_hostile menunjukkan apakah NPC bersifat agresif.
    private boolean is_hostile;

    // dialog_list menyimpan kumpulan dialog yang dapat diucapkan NPC.
    private List<String> dialog_list;

    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor tanpa parameter.
    // Dialog diinisialisasi sebagai list kosong.
    public NPC() {
        this.tipe_npc = "";
        this.is_hostile = false;
        this.dialog_list = new ArrayList<>();
    }

    // Constructor berparameter.
    // Constructor parent Karakter dipanggil untuk menginisialisasi atribut dasar.
    // Kumpulan dialog disalin agar NPC memiliki list dialog sendiri.
    public NPC(String id, String nama, int level, int hp, int max_hp, String tipe_npc, boolean is_hostile,
            List<String> dialog_list) {
        super(id, nama, level, hp, max_hp);
        this.tipe_npc = tipe_npc;
        this.is_hostile = is_hostile;
        this.dialog_list = new ArrayList<>(dialog_list);
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter tipe NPC digunakan untuk mengubah peran NPC.
    public void setTipeNpc(String tipe_npc) {
        this.tipe_npc = tipe_npc;
    }

    // Getter tipe NPC digunakan untuk mengambil peran NPC.
    public String getTipeNpc() {
        return tipe_npc;
    }

    // Setter is_hostile digunakan untuk mengubah status agresivitas NPC.
    public void setIsHostile(boolean is_hostile) {
        this.is_hostile = is_hostile;
    }

    // Getter is_hostile digunakan untuk mengambil status agresivitas NPC.
    public boolean getIsHostile() {
        return is_hostile;
    }

    // Setter dialog list digunakan untuk mengganti seluruh kumpulan dialog NPC.
    // List disalin agar perubahan pada list asal tidak mengubah atribut NPC.
    public void setDialogList(List<String> dialog_list) {
        this.dialog_list = new ArrayList<>(dialog_list);
    }

    // Getter dialog list digunakan untuk mengambil kumpulan dialog NPC.
    // Salinan list dikembalikan agar atribut internal tidak diubah langsung.
    public List<String> getDialogList() {
        return new ArrayList<>(dialog_list);
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Menampilkan seluruh informasi NPC.
    // Informasi dasar karakter ditampilkan oleh class Karakter.
    public void tampilkan_info() {
        super.tampilkan_info();
        System.out.println("Tipe NPC        : " + tipe_npc);
        System.out.println("Hostile         : " + (is_hostile ? "Ya" : "Tidak"));
        System.out.println("Dialog          :");

        // Menampilkan seluruh dialog yang dimiliki NPC.
        for (String dialog : dialog_list) {
            System.out.println("  - " + dialog);
        }
    }
}