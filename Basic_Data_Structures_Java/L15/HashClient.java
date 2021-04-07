package Basic_Data_Structures_15;

public class HashClient {

	public static void main(String[] args) {
		

		HashMap<String, Integer> map = new HashMap<>();
		
		map.put("Ind", 220);
		map.put("Aus", 210);
		map.put("Pak", 110);
		map.put("BD", 150);
		map.put("Afg", 180);
		map.put("SL", 205);
		
		map.display();
		
		System.out.println(map.get("Ind"));
		System.out.println(map.get("SV"));
		
		map.remove("Pak");
		map.display();
		
		map.put("S", 220);
		map.put("T", 210);
		map.put("U", 110);
		map.put("V", 150);
		map.put("W", 180);
		map.put("X", 205);
//		map.put("Y", 480);
		map.display();
		map.put("Aus", 5000);
		map.display();
		System.out.println(map.keySet());
		
		for(String key: map.keySet()) {
			
			System.out.println(map.get(key));
		}
		
	}

}
