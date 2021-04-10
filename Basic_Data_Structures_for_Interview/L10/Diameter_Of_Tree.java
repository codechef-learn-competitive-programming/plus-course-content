package Basic_Data_Structures_Batch_2_Class_10;

public class Diameter_Of_Tree {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	class DiaPair {
		int dia;
		int h;
	}
	
	class Node {
		int data;
		Node left;
		Node right;
	}
	
	private DiaPair diameter(Node node) {
		
		if(node == null) {
			DiaPair p = new DiaPair();
			p.dia = 0;
			p.h = -1;
			return p;
		}
		
		DiaPair rightD = diameter(node.right);
		DiaPair leftD = diameter(node.left);
		
		
		DiaPair myres = new DiaPair();
		myres.h = Math.max(rightD.h, leftD.h) + 1;
		
		int ld = leftD.dia;
		int rd  = rightD.dia;
		
		int sd = rightD.h + leftD.h + 2;
		
		myres.dia = Math.max(ld, Math.max(rd, sd));
		
		return myres;
		
	}

}
