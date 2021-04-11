package Basic_Data_Structures_Batch_2_Class_11;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

import org.w3c.dom.Node;

public class Right_View {

	public static void main(String[] args) {

	}

	class Node {
		int val;
		Node left;
		Node right;
	}

	ArrayList<Integer> rightView(Node root) {

		ArrayList<Integer> list = new ArrayList<>();

		if (root == null) {
			return list;
		}

		Queue<Node> primary = new LinkedList<>();
		Queue<Node> helper = new LinkedList<>();

		primary.add(root);
		list.add(root.val);

		while (!primary.isEmpty()) {

			Node n = primary.remove();
			if (n.right != null) {
				helper.add(n.right);
			}

			if (n.left != null) {
				helper.add(n.left);
			}

			if (primary.isEmpty()) {
				if (!helper.isEmpty()) {
					list.add(helper.element().val);
					primary = helper;
					helper = new LinkedList<>();
				}
			}
		}

		return list;
	}

}
