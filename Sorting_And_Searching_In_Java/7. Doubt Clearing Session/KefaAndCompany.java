import java.util.*;
import java.io.*;

public class KefaAndCompany {
	public static void main(String[] args) throws java.lang.Exception {
		BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(x.readLine());
		int n = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		int[] m = new int[n];
		int[] s = new int[n];
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(x.readLine());
			m[i] = Integer.parseInt(st.nextToken());
			s[i] = Integer.parseInt(st.nextToken());
		}
		
		totalFriendship(m, s, n, d);
	}

	private static void totalFriendship(int[] m, int[] s, int n, int d) {
		Friend[] pairs = new Friend[n];
		for(int i = 0; i < n; i++) {
			pairs[i] = new Friend(m[i], s[i]);
		}
		
		//Ascending order of money
		Arrays.sort(pairs, (e1, e2) -> e1.money - e2.money);
		//Two pointers i -> Pointer to poorest guy of group
		//j -> Pointer to richest guy in group
		int i = 0, j = 0;
		long currentFriendship = 0, maxFriendship = 0;
		while(j < n) {
			if(pairs[j].money - pairs[i].money < d) {
				currentFriendship += pairs[j].friendship;
				maxFriendship = Math.max(maxFriendship, currentFriendship);
				j++;
			} else {
				currentFriendship -= pairs[i].friendship;
				i++;
			}

		}
		
		System.out.println(maxFriendship);
	}
}

class Friend {
	int money, friendship;
	Friend(int money, int friendship) {
		this.money = money;
		this.friendship = friendship;
	}
	@Override
	public String toString() {
		return "Friend [money=" + money + ", friendship=" + friendship + "]";
	}
	
}