
// mapa com a qtde de times com vaga de uma determinada uni
var uni_count = {};

// mapa com a qtde de times com vaga de uma determinada sede
var sede_count = {};

// qtde de vagas da regra 1 (25%).
var qtde_vagas_1 = 15;

var null_background   = '#ffffff'; // white
var regra1_background = '#008000'; // green
var regra2_background = '#ffff00'; // yellow
var sem_vaga_uni      = '#A9A9A9'; // grey
var sem_vaga_sede     = '#D3D3D3'; // grey darker

function formatting() {
  var main_sheet = SpreadsheetApp.openById("19Q0Z1FZQlY7nYkUYsXGlQ93TNrnaRZ_MTp2B1lbMxaE").getSheetByName("Ranking");
  var main_data = main_sheet.getDataRange().getValues();
  var sedes_sheet = SpreadsheetApp.openById("19Q0Z1FZQlY7nYkUYsXGlQ93TNrnaRZ_MTp2B1lbMxaE").getSheetByName("Vagas");
  var sedes_data = sedes_sheet.getDataRange().getValues();
  
  // limpa as formatações anteriores (quando é preciso resetar)
  //main_sheet.getRange(1, 1, main_data.length, 16).setBackground(null_background);
  
  // regra 1
  // vagas para os primeiros N colocados
  // há um limite de 2 times da mesma universidade
  var i;
  for(i=1, k=0; i<main_data.length && k<qtde_vagas_1; i++) {
    var uni = main_data[i][1];
    var count = uni_count[uni];
    if(count == undefined) count = 0;
    
    if(count < 2) {
      uni_count[uni] = count+1;
      changeColor(main_sheet, i+1, 1, main_data[i].length, regra1_background);
      k++;
    } else {
      changeColor(main_sheet, i+1, 1, main_data[i].length, sem_vaga_uni);
    }
  }
  
  // regra 2
  // vagas para os melhores de suas sedes (ignorando os q ja tem vaga na regra 1)
  // há um limite de 1 time da mesma universidade
  for(; i<main_data.length; i++) {
    // elimina café-com-leite
    if(main_data[i][4] == "null") {
      changeColor(main_sheet, i+1, 1, main_data[i].length, sem_vaga_uni);
      continue;
    }
    
    // ignora os da regra 1
    if(main_sheet.getRange(i+1, 1).getBackground() == regra1_background) {
      continue;
    }
    
    var uni = main_data[i][1];
    var count_uni = uni_count[uni];
    if(count_uni == undefined) count_uni = 0;
    
    if(count_uni < 1) {
      // verifica se existem vagas naquela sede
      for(var j=1; j<sedes_data.length; j++) {
        if(sedes_data[j][2] == main_data[i][4]) {
          var count = sede_count[ sedes_data[j][2] ];
          if(count == undefined) count = 0;
          
          if(count < sedes_data[j][1]) {
            sede_count[ sedes_data[j][2] ] = count+1;
            uni_count[ uni ] = count_uni+1;
            changeColor(main_sheet, i+1, 1, main_data[i].length, regra2_background);
          } else {
            changeColor(main_sheet, i+1, 1, main_data[i].length, sem_vaga_sede);
          }
        }
      }
    } else {
      // a uni já atingiu o limite de vagas
      changeColor(main_sheet, i+1, 1, main_data[i].length, sem_vaga_uni);
    }
  }
}

function changeColor(sheet, row, col, col_length, background) {
  if(sheet.getRange(row, col, 1, col_length).getBackground() != background) {
    sheet.getRange(row, col, 1, col_length).setBackground(background);
  }
}
