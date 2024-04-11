#include <stdio.h>
#include "vec.h"

int main(void)
{
  vec_t *vec = new_vec();
  vec_cst(vec);

  vec_size(vec);
  vec_capacity(vec);

  vec_push(vec, 55);
  vec_size(vec);  
  vec_capacity(vec);
  
  vec_push(vec, 57);
  vec_push(vec, 58);
  vec_push(vec, 59);
  vec_size(vec);
  
  vec_capacity(vec);
  vec_push(vec, 60);
  vec_size(vec);  
  vec_capacity(vec);

  for(int i = 0; i < vec_end(vec); i++){
	vec_item(vec, i);
  }
   
   vec_free(vec);
  
  return 0;
}
