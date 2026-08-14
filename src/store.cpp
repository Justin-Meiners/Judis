#include "judis/store.hpp"

namespace judis {

void KeyValueStore::set(const std::string& key, const std::string& value) {
    data_.insert_or_assign(key, value);
}

std::optional<std::string> KeyValueStore::get(const std::string& key) const {
    auto it = data_.find(key);
    if (it == data_.end()) {
        return std::nullopt;
    }
    return it->second;
}

bool KeyValueStore::erase(const std::string& key) {
    return data_.erase(key) > 0;
}

bool KeyValueStore::exists(const std::string& key) const {
    return data_.find(key) != data_.end();
}

std::size_t KeyValueStore::size() const {
    return data_.size();
}

} 

