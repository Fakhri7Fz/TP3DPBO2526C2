class Inventory
{
private:
    // =========================
    // ATTRIBUTE
    // =========================

    // Kapasitas maksimal menunjukkan jumlah slot maksimum yang dapat digunakan oleh Inventory.
    int kapasitas_maksimal;

    // Vector daftar_item menyimpan kumpulan object Item yang dimiliki oleh Player.
    // Karena Item disimpan langsung sebagai object di dalam Inventory, hubungan Inventory dengan Item merupakan Composition.
    vector<Item> daftar_item;

public:
    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor kosong.
    // Constructor ini dibuat agar object Inventory dapat dibuat tanpa memberikan nilai awal.
    Inventory() {}

    // Constructor berparameter.
    // Constructor ini digunakan untuk menentukan kapasitas maksimal Inventory ketika object dibuat.
    Inventory(int kapasitas_maksimal)
    {
        this->kapasitas_maksimal = kapasitas_maksimal;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter kapasitas maksimal digunakan untuk mengubah kapasitas Inventory.
    // Kapasitas tidak boleh lebih kecil dari jumlah Item yang sudah tersimpan di dalam Inventory.
    void setKapasitasMaksimal(int kapasitas_maksimal)
    {
        if (kapasitas_maksimal < 0)
        {
            cout << "Error: kapasitas tidak boleh negatif.\n";
        }
        else if (kapasitas_maksimal >= daftar_item.size())
        {
            this->kapasitas_maksimal = kapasitas_maksimal;
        }
        else
        {
            cout << "Error: kapasitas tidak boleh lebih kecil dari jumlah item saat ini.\n";
        }
    }

    // Getter kapasitas maksimal digunakan untuk mengambil kapasitas maksimum Inventory.
    int getKapasitasMaksimal() const
    {
        return kapasitas_maksimal;
    }

    // Getter daftar item digunakan untuk mengambil seluruh object Item yang tersimpan di dalam Inventory.
    vector<Item> getDaftarItem() const
    {
        return daftar_item;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Menambahkan object Item ke dalam Inventory.
    // Item hanya dapat ditambahkan apabila jumlah slot yang digunakan masih lebih kecil dari kapasitas maksimal.
    void tambahItem(Item item)
    {
        if (daftar_item.size() < kapasitas_maksimal)
        {
            daftar_item.push_back(item);
        }
        else
        {
            cout << "Error: Inventory sudah penuh.\n";
        }
    }

    // Menampilkan seluruh Item yang terdapat di dalam Inventory.
    void tampilkan_info() const
    {
        cout << "Kapasitas       : " << daftar_item.size() << "/" << kapasitas_maksimal << endl;
        cout << "Daftar Item:" << endl;

        if (daftar_item.empty())
        {
            cout << "  Inventory kosong." << endl;
        }
        else
        {
            // Menampilkan setiap Item yang tersimpan di dalam vector daftar_item.
            for (int i = 0; i < daftar_item.size(); i++)
            {
                cout << endl;
                cout << "  Item ke-" << i + 1 << endl;
                cout << "  ID Item       : " << daftar_item[i].getIdItem() << endl;
                cout << "  Nama Item     : " << daftar_item[i].getNamaItem() << endl;
                cout << "  Tipe Item     : " << daftar_item[i].getTipeItem() << endl;
                cout << "  Berat         : " << daftar_item[i].getBerat() << " kg" << endl;
                cout << "  Harga Jual    : Rp" << daftar_item[i].getHargaJual() << endl;
                cout << "  Quantity      : " << daftar_item[i].getQuantity() << endl;
            }
        }
    }

    // =========================
    // DESTRUCTOR
    // =========================

    // Destructor dipanggil ketika object Inventory dihancurkan.
    // Karena Item disimpan sebagai object langsung di dalam vector Inventory, Item juga akan dihancurkan secara otomatis ketika Inventory dihancurkan.
    ~Inventory()
    {
    }
};