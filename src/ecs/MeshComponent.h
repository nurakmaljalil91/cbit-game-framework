#ifndef MESHCOMPONENT_H
#define MESHCOMPONENT_H

#include "Component.h"
#include "../core/Mesh.h"
#include "../core/Texture.h"

#include <string>

class MeshComponent : public Component
{
private:
    Mesh mMesh;
    Texture mTexture;

    size_t mTextureIndex;

public:
    MeshComponent(Mesh mesh, size_t index)
    {
        mMesh = mesh;
        mTextureIndex = index;
    }

    MeshComponent(std::string meshfile, std::string texturefile)
    {
        mMesh.LoadOBJ(meshfile);
        mTexture.LoadTexture(texturefile, true);
    }

    void Initialize() override {}
    void Update(float deltaTime) override {}
    void Render(ShaderProgram *shader) override
    {
        glm::mat4 temp(1.0);
        temp = glm::translate(glm::mat4(), owner->transform.position) * glm::scale(glm::mat4(), owner->transform.scale);
        shader->SetUniform("model", owner->GetWorldPosition());
        mTexture.Bind(0);
        mMesh.Draw();
        mTexture.Unbind(0);
    }
};

#endif // COMPONENT_H