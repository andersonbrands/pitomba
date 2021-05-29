
#ifndef UNORDERED_MAP_CONTAINER_H_
#define UNORDERED_MAP_CONTAINER_H_


#include "iContainer.h"
#include <cassert>
#include <unordered_map>

using namespace std;

namespace pitomba {

    template <typename ObjectId, typename Object>
    class UnorderedMapContainer : public iContainer<ObjectId, Object> {
    private:
        using ObjectMap = unordered_map<ObjectId, Object*>;

        ObjectMap objects_;

        void release() {
            for (auto iter = objects_.begin(); iter != objects_.end(); ++iter) {
                Object* pObject = iter->second;
                if (pObject) {
                    delete pObject;
                    pObject = nullptr;
                }
            }
        }

    public:
        UnorderedMapContainer() = default;

        virtual ~UnorderedMapContainer() {
            release();
        };

        Object* add(const ObjectId id) override {
            Object* pNewObject(nullptr);

            bool added(false);

            auto iter = objects_.find(id);
            if (iter == objects_.end()) {
                pNewObject = new Object();
                if (pNewObject) {
                    pair<ObjectId, Object*> newObject(id, pNewObject);
                    auto addedIter = objects_.insert(newObject);

                    added = addedIter.second;
                }
            } else {
                return iter->second;
            }

            if (added) {
                return pNewObject;
            } else {
                return nullptr;
            }
        }

        Object* get(const ObjectId id) override {
            Object* pNewObject(nullptr);

            auto iter = objects_.find(id);

            if (iter != objects_.end()) {
                pNewObject = iter->second;
            }

            return pNewObject;
        }

        void remove(const ObjectId id) override {
            auto iter = objects_.find(id);

            assert(iter != objects_.end());

            Object* pObejct(iter->second);
            delete pObejct;
            pObejct = nullptr;

            objects_.erase(iter);
        }

        void clear() override {
            release();
            objects_.clear();
        }
    };

}

#endif // UNORDERED_MAP_CONTAINER_H_
