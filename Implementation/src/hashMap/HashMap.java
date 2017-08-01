package hashMap;

import java.util.Map;

/**
 * Created by Xiaojun YU on 2017-03-15.
 */
public class HashMap {
    public <strong> transient Map.Entry<K, V>[] table;
    transient int size;
    int threshold;
    final float localFactor;

    static class Entry<K, V> implements Map.Entry<> {
        /*
        final K key;
        V value;
        Entry<K, V> next;
        int hash;
        */

        public V put(K key, V value) {
            if (key == null) {
                return putForNullKey(value);
            }
            int hash = hash(key);
            int i = indexFor(hash, this.table.length);
            for (Entry<K, V> e = table[i]; e != null; e = e.next) {
                Object k;
                if (e.hash == hash && ((k = e.key) == key || key.equals(k))) {
                    V oldValue = e.value;
                    e.value = value;
                    e.recordAccess(this);
                    return oldValue;
                }
            }

            modCount++;
            addEntry(hash, key, value, i);
            return null;
        }
        private V putForNullKey(V value) {
            for (Entry<K, V> e = table[0]; e != null; e = e.next) {
                if (e.key == null) {
                    V oldValue = e.value;
                    e.value = value;
                    e.recordAccess(this);
                    return oldValue;
                }
            }
            modCount++;
            addEntry(0, null, value, 0);
            return null;
        }
        @Override
        public Object getKey() {
            return null;
        }

        @Override
        public Object getValue() {
            return null;
        }

        @Override
        public Object setValue(Object value) {
            return null;
        }
    }
}
