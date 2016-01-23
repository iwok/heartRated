 void createTable(){
 if(BPM>=0){
  TableRow newRow = table.addRow();
  newRow.setInt("TIME", table.getRowCount() - 1);
  newRow.setInt("BPM", BPM);
   
 saveTable(table, "data/data.csv"); 
 }
 }
 
 void drawTableData(){
   
  table = loadTable("data/data.csv", "header");

  println(table.getRowCount() + " total rows in table"); 

  for (TableRow row : table.rows()) {
    
    int time = row.getInt("TIME");
    String bpm = row.getString("BPM");
    
    println("Time: "+time+" BPM: "+bpm);
  }
   
   
 }
