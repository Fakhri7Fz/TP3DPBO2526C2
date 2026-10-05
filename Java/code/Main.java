import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Scanner digunakan bersama untuk membaca input terminal.
    private static final Scanner scanner = new Scanner(System.in);

    // =========================================================
    // FUNGSI INPUT
    // =========================================================

    // Menerima input integer dan mengulang jika input tidak valid.
    private static int inputInteger(String pesan) {
        while (true) {
            System.out.print(pesan);
            String nilai = scanner.nextLine();

            try {
                return Integer.parseInt(nilai.trim());
            } catch (NumberFormatException error) {
                System.out.println("Error: input harus berupa angka.");
            }
        }
    }

    // Menerima input integer dengan batas minimum.
    private static int inputIntegerMin(String pesan, int nilaiMinimum) {
        while (true) {
            int nilai = inputInteger(pesan);

            if (nilai >= nilaiMinimum) {
                return nilai;
            }

            System.out.println("Error: nilai minimal adalah " + nilaiMinimum + ".");
        }
    }

    // Menerima input float dan mengulang jika input tidak valid.
    private static float inputFloat(String pesan) {
        while (true) {
            System.out.print(pesan);
            String nilai = scanner.nextLine();

            try {
                return Float.parseFloat(nilai.trim());
            } catch (NumberFormatException error) {
                System.out.println("Error: input harus berupa angka.");
            }
        }
    }

    // Menerima input float dengan batas minimum.
    private static float inputFloatMin(String pesan, float nilaiMinimum) {
        while (true) {
            float nilai = inputFloat(pesan);

            if (nilai >= nilaiMinimum) {
                return nilai;
            }

            System.out.println("Error: nilai minimal adalah " + nilaiMinimum + ".");
        }
    }

    // Menerima string yang tidak boleh kosong.
    private static String inputString(String pesan) {
        while (true) {
            System.out.print(pesan);
            String nilai = scanner.nextLine();

            if (!nilai.isEmpty()) {
                return nilai;
            }

            System.out.println("Error: input tidak boleh kosong.");
        }
    }

    // =========================================================
    // FUNGSI CEK ID KARAKTER
    // =========================================================

    // Mengecek apakah ID sudah digunakan oleh Player atau NPC.
    private static boolean idKarakterSudahAda(String id, List<Player> daftarPlayer, List<NPC> daftarNpc) {
        for (Player player : daftarPlayer) {
            if (player.getId().equals(id)) {
                return true;
            }
        }

        for (NPC npc : daftarNpc) {
            if (npc.getId().equals(id)) {
                return true;
            }
        }

        return false;
    }

    // Mengecek apakah ID Item sudah digunakan oleh Item lain.
    private static boolean idItemSudahAda(String idItem, List<Item> daftarItem) {
        for (Item item : daftarItem) {
            if (item.getIdItem().equals(idItem)) {
                return true;
            }
        }

        return false;
    }

    // =========================================================
    // FUNGSI TAMBAH PLAYER
    // =========================================================

    // Membuat Player baru beserta Inventory dan Item-nya melalui input terminal.
    private static void tambahPlayer(List<Player> daftarPlayer, List<NPC> daftarNpc) {
        System.out.println();
        System.out.println("============================================");
        System.out.println("              TAMBAH PLAYER                 ");
        System.out.println("============================================");

        // Meminta ID karakter yang unik di seluruh Player dan NPC.
        String id;

        while (true) {
            id = inputString("ID              : ");

            if (!idKarakterSudahAda(id, daftarPlayer, daftarNpc)) {
                break;
            }

            System.out.println("Error: ID sudah digunakan oleh karakter lain.");
        }

        String nama = inputString("Nama            : ");
        int level = inputIntegerMin("Level           : ", 0);
        int maxHp = inputIntegerMin("Max HP          : ", 1);
        int hp;

        // Memastikan HP tidak melebihi max HP.
        while (true) {
            hp = inputIntegerMin("HP              : ", 0);

            if (hp <= maxHp) {
                break;
            }

            System.out.println("Error: HP tidak boleh lebih besar dari Max HP.");
        }

        int exp = inputIntegerMin("Experience      : ", 0);
        int gold = inputIntegerMin("Gold            : ", 0);

        // Membuat Player dengan atribut dasar dan atribut khusus Player.
        Player player = new Player(id, nama, level, hp, maxHp, exp, gold);

        // Meminta kapasitas Inventory.
        int kapasitas = inputIntegerMin("Kapasitas Inventory : ", 1);
        player.getInventory().setKapasitasMaksimal(kapasitas);

        // Jumlah Item tidak boleh melebihi kapasitas Inventory.
        int jumlahItem;

        while (true) {
            jumlahItem = inputIntegerMin("Jumlah Item        : ", 0);

            if (jumlahItem <= kapasitas) {
                break;
            }

            System.out.println("Error: jumlah Item tidak boleh melebihi kapasitas Inventory (" + kapasitas + ").");
        }

        // Membuat setiap Item berdasarkan input.
        for (int i = 0; i < jumlahItem; i++) {
            System.out.println();
            System.out.println("Item ke-" + (i + 1));

            String idItem;
            while (true) {
                idItem = inputString("ID Item         : ");

                if (!idItemSudahAda(idItem, player.getInventory().getDaftarItem())) {
                    break;
                }

                System.out.println("Error: ID Item sudah digunakan dalam Inventory Player ini.");
            }

            String namaItem = inputString("Nama Item       : ");
            String tipeItem = inputString("Tipe Item       : ");
            float berat = inputFloatMin("Berat (kg)      : ", 0);
            int hargaJual = inputIntegerMin("Harga Jual      : Rp", 0);
            int quantity = inputIntegerMin("Quantity        : ", 0);

            Item item = new Item(
                    idItem,
                    namaItem,
                    tipeItem,
                    berat,
                    hargaJual,
                    quantity);

            player.getInventory().tambahItem(item);
        }

        daftarPlayer.add(player);
        System.out.println();
        System.out.println("Player berhasil ditambahkan.");
    }

    // =========================================================
    // FUNGSI TAMBAH NPC
    // =========================================================

    // Membuat NPC baru beserta dialognya melalui input terminal.
    private static void tambahNPC(List<NPC> daftarNpc, List<Player> daftarPlayer) {
        System.out.println();
        System.out.println("============================================");
        System.out.println("                TAMBAH NPC                  ");
        System.out.println("============================================");

        // Meminta ID karakter yang unik di seluruh Player dan NPC.
        String id;

        while (true) {
            id = inputString("ID              : ");

            if (!idKarakterSudahAda(id, daftarPlayer, daftarNpc)) {
                break;
            }

            System.out.println("Error: ID sudah digunakan oleh karakter lain.");
        }

        String nama = inputString("Nama            : ");
        int level = inputIntegerMin("Level           : ", 0);
        int maxHp = inputIntegerMin("Max HP          : ", 1);
        int hp;

        // Memastikan HP tidak melebihi max HP.
        while (true) {
            hp = inputIntegerMin("HP              : ", 0);

            if (hp <= maxHp) {
                break;
            }

            System.out.println("Error: HP tidak boleh lebih besar dari Max HP.");
        }

        System.out.println();
        System.out.println("Tipe / peran NPC di dalam game.");
        System.out.println("Contoh: Penjual, Pemberi Quest, atau Musuh.");
        String tipeNpc = inputString("Tipe NPC        : ");

        System.out.println();
        System.out.println("Apakah NPC bersifat agresif dan dapat menyerang Player?");
        System.out.println("1 = Ya, NPC bersifat agresif/musuh.");
        System.out.println("0 = Tidak, NPC tidak menyerang Player.");

        // Memastikan input status hostile hanya 0 atau 1.
        int hostileInput;

        while (true) {
            hostileInput = inputInteger("Hostile? (1 = Ya, 0 = Tidak): ");

            if (hostileInput == 0 || hostileInput == 1) {
                break;
            }

            System.out.println("Error: masukkan 1 atau 0.");
        }

        boolean isHostile = hostileInput == 1;
        int jumlahDialog = inputIntegerMin("Jumlah Dialog   : ", 1);
        List<String> dialogList = new ArrayList<>();

        // Meminta setiap dialog NPC.
        for (int i = 0; i < jumlahDialog; i++) {
            String dialog = inputString("Dialog ke-" + (i + 1) + " : ");
            dialogList.add(dialog);
        }

        NPC npc = new NPC(
                id,
                nama,
                level,
                hp,
                maxHp,
                tipeNpc,
                isHostile,
                dialogList);

        daftarNpc.add(npc);
        System.out.println();
        System.out.println("NPC berhasil ditambahkan.");
    }

    // =========================================================
    // FUNGSI TAMPILKAN SEMUA DATA
    // =========================================================

    // Menampilkan seluruh Player, Inventory, Item, dan NPC.
    private static void tampilkanSemuaData(List<Player> daftarPlayer, List<NPC> daftarNpc) {
        System.out.println();
        System.out.println("============================================");
        System.out.println("              DATA GAME                     ");
        System.out.println("============================================");

        System.out.println();
        System.out.println("--------------- PLAYER --------------------");

        if (daftarPlayer.isEmpty()) {
            System.out.println("Belum ada data Player.");
        } else {
            for (int i = 0; i < daftarPlayer.size(); i++) {
                Player player = daftarPlayer.get(i);

                System.out.println();
                System.out.println("Player ke-" + (i + 1));
                System.out.println("--------------------------------------------");
                player.tampilkan_info();

                System.out.println();
                System.out.println("Inventory:");
                player.getInventory().tampilkan_info();
            }
        }

        System.out.println();
        System.out.println("---------------- NPC ----------------------");

        if (daftarNpc.isEmpty()) {
            System.out.println("Belum ada data NPC.");
        } else {
            for (int i = 0; i < daftarNpc.size(); i++) {
                NPC npc = daftarNpc.get(i);

                System.out.println();
                System.out.println("NPC ke-" + (i + 1));
                System.out.println("--------------------------------------------");
                npc.tampilkan_info();
            }
        }
    }

    // =========================================================
    // PROGRAM UTAMA
    // =========================================================

    public static void main(String[] args) {
        // Membuat Item awal.
        Item pedang = new Item("I001", "Pedang Besi", "Senjata", 5.0f, 500, 1);
        Item potion = new Item("I002", "Ramuan Penyembuh", "Konsumsi", 0.5f, 100, 5);
        Item armor = new Item("I003", "Armor Besi", "Armor", 8.0f, 750, 1);

        // Membuat Player awal beserta Inventory dan Item-nya.
        Player player1 = new Player("P001", "Kiryu", 10, 100, 100, 2500, 1000);
        player1.getInventory().setKapasitasMaksimal(5);
        player1.getInventory().tambahItem(pedang);
        player1.getInventory().tambahItem(potion);

        Player player2 = new Player("P002", "Akira", 7, 80, 100, 1500, 750);
        player2.getInventory().setKapasitasMaksimal(5);
        player2.getInventory().tambahItem(armor);

        List<Player> daftarPlayer = new ArrayList<>();
        daftarPlayer.add(player1);
        daftarPlayer.add(player2);

        // Membuat NPC awal beserta daftar dialognya.
        List<String> dialogMerchant = new ArrayList<>();
        dialogMerchant.add("Selamat datang di toko!");
        dialogMerchant.add("Apakah kamu ingin membeli sesuatu?");

        NPC merchant = new NPC(
                "N001", "Merchant", 5, 80, 80,
                "Penjual", false, dialogMerchant);

        List<String> dialogEnemy = new ArrayList<>();
        dialogEnemy.add("Berani sekali kamu datang ke sini!");
        dialogEnemy.add("Aku akan mengalahkanmu!");

        NPC goblin = new NPC(
                "N002", "Goblin", 8, 120, 120,
                "Musuh", true, dialogEnemy);

        List<NPC> daftarNpc = new ArrayList<>();
        daftarNpc.add(merchant);
        daftarNpc.add(goblin);

        // Menampilkan data awal sebelum menu dijalankan.
        System.out.println();
        System.out.println("============================================");
        System.out.println("       DATA GAME SEBELUM DITAMBAHKAN        ");
        System.out.println("============================================");
        tampilkanSemuaData(daftarPlayer, daftarNpc);

        // Menampilkan menu sampai user memilih keluar.
        int pilihan;

        do {
            System.out.println();
            System.out.println("============================================");
            System.out.println("                MENU GAME                   ");
            System.out.println("============================================");
            System.out.println("1. Tambah Player");
            System.out.println("2. Tambah NPC");
            System.out.println("3. Tampilkan Semua Data");
            System.out.println("0. Keluar");
            System.out.println("============================================");

            pilihan = inputInteger("Pilih menu: ");

            switch (pilihan) {
                case 1:
                    tambahPlayer(daftarPlayer, daftarNpc);
                    break;
                case 2:
                    tambahNPC(daftarNpc, daftarPlayer);
                    break;
                case 3:
                    tampilkanSemuaData(daftarPlayer, daftarNpc);
                    break;
                case 0:
                    System.out.println();
                    System.out.println("Program selesai.");
                    break;
                default:
                    System.out.println("Error: pilihan menu tidak tersedia.");
                    break;
            }
        } while (pilihan != 0);

        // Menampilkan seluruh data terbaru sebelum program berakhir.
        System.out.println();
        System.out.println("============================================");
        System.out.println("        DATA GAME SETELAH DITAMBAHKAN       ");
        System.out.println("============================================");
        tampilkanSemuaData(daftarPlayer, daftarNpc);

        scanner.close();
    }
}