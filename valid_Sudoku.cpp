class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        char fijo;

        for (int j = 0; j < 9; j++ ){       // Recorrido de columnas
            for (int i = 0; i < 9; i++){    // Recorrido de filas
                fijo = board[j][i];
                for (int k =0; k<9; k++){
                    if ( i != k ){
                        if ( (board[j][k] == fijo) && (board[j][k] != '.') ){
                            return false;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++ ){      // Recorrido de columnas
            for (int j = 0; j < 9; j++){    // Recorrido de filas
                fijo = board[j][i];
                for (int k = 0; k < 9; k++){
                    if ( j != k ){
                        if ( (board[k][i] == fijo) && (board[k][i] != '.') ){
                            return false;
                        }
                    }
                }   
            }
        }

        for (int lim_col = 0; lim_col < 9; lim_col += 3){
            for (int lim_fila = 0; lim_fila < 9; lim_fila += 3){
                for (int j = lim_col; j < (lim_col+3); j++ ){           // Recorrido de numeros dendro de una columna
                    for (int i = lim_fila; i < (lim_fila+3); i++){      // Recorrido de nuemros dentro de una fila
                        fijo = board[j][i]; 
                        for (int k = lim_col; k < (lim_col+3); k++){
                            for (int w = lim_fila; w < (lim_fila+3); w++){
                                if ( !((i==w)&&(j==k)) ){
                                    if( (fijo == board[k][w]) &&  (board[k][w]!='.') ){
                                        return false;
                                    } 
                                }
                            }
                        }      
                    }
                }
            }
            
        }
        
        return true;

    }
};
