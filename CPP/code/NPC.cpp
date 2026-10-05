class NPC : public Karakter
{
private:
    // =========================
    // ATTRIBUTE
    // =========================

    // Tipe NPC menunjukkan peran NPC di dalam game, misalnya Penjual, Pemberi Quest, atau Musuh.
    string tipe_npc;

    // is_hostile menunjukkan apakah NPC bersifat agresif dan dapat menyerang Player.
    bool is_hostile;

    // dialog_list menyimpan kumpulan dialog yang dapat diucapkan oleh NPC.
    vector<string> dialog_list;

public:
    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor kosong.
    // Constructor ini dibuat agar object NPC dapat dibuat tanpa memberikan nilai awal.
    NPC() {}

    // Constructor berparameter.
    // Constructor parent Karakter dipanggil melalui initializer list
    // untuk menginisialisasi bagian Karakter dari object NPC.
    // Setelah itu, atribut khusus NPC diisi di dalam body constructor.
    NPC(string id, string nama, int level, int hp, int max_hp,
        string tipe_npc, bool is_hostile, vector<string> dialog_list)
        : Karakter(id, nama, level, hp, max_hp)
    {
        this->tipe_npc = tipe_npc;
        this->is_hostile = is_hostile;
        this->dialog_list = dialog_list;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter tipe NPC digunakan untuk mengubah peran NPC.
    void setTipeNpc(string tipe_npc)
    {
        this->tipe_npc = tipe_npc;
    }

    // Getter tipe NPC digunakan untuk mengambil peran NPC.
    string getTipeNpc() const
    {
        return tipe_npc;
    }

    // Setter is_hostile digunakan untuk mengubah status agresivitas NPC.
    void setIsHostile(bool is_hostile)
    {
        this->is_hostile = is_hostile;
    }

    // Getter is_hostile digunakan untuk mengambil status agresivitas NPC.
    bool getIsHostile() const
    {
        return is_hostile;
    }

    // Setter dialog list digunakan untuk mengganti seluruh kumpulan dialog yang dimiliki NPC.
    void setDialogList(vector<string> dialog_list)
    {
        this->dialog_list = dialog_list;
    }

    // Getter dialog list digunakan untuk mengambil seluruh kumpulan dialog NPC.
    vector<string> getDialogList() const
    {
        return dialog_list;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Menampilkan seluruh informasi NPC.
    // Atribut ID, nama, level, HP, dan max HP berasal dari class Karakter melalui inheritance.
    void tampilkan_info() const
    {
        cout << "ID              : " << id << endl;
        cout << "Nama            : " << nama << endl;
        cout << "Level           : " << level << endl;
        cout << "HP              : " << hp << "/" << max_hp << endl;
        cout << "Tipe NPC        : " << tipe_npc << endl;
        cout << "Hostile         : " << (is_hostile ? "Ya" : "Tidak") << endl;

        cout << "Dialog          :" << endl;

        // Menampilkan seluruh dialog yang dimiliki NPC.
        for (int i = 0; i < dialog_list.size(); i++)
        {
            cout << "  - " << dialog_list[i] << endl;
        }
    }

    // =========================
    // DESTRUCTOR
    // =========================

    // Destructor dipanggil ketika object NPC dihancurkan.
    ~NPC()
    {
    }
};