#ifndef VOXEL_H
#define VOXEL_H


/**
 * @brief O Struct tipo Voxel é um tipo de dados que esta sendo utlizado para gerar a matriz 3D
 * @details
 * - atributo r do tipo float referece a cor vermalha que vai de 0.00 a 1.00
 * - atributo g do tipo float referece a cor verde que vai de 0.00 a 1.00
 * - atributo b do tipo float referece a cor azul que vai de 0.00 a 1.00
 * - atributo a do tipo float referece a opacidade da cor que vai e 0.00 a 1.00
 * - atibuto isOn do tipo bool referece a capacidade de mostar a cor pode ser verdadeiro ou falso
 */
struct Voxel {
  float r,g,b; // Colors
  float a; // obacidade
            // Transparency
  bool isOn; // Included or not
};

#endif // VOXEL_H
