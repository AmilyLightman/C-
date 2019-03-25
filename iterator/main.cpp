import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class LinkedList2 {
private class Node {
    public int val;
    public Node next;
    }

private Node head;
private Node tail;

public LinkedList2() {
        head = tail = null;
    }

public static class Iterator {
    private LinkedList2 l;
    private Node pos;

    public Iterator(LinkedList2 l) {
            this.l = l;
            pos = l.head;
        }

    public boolean hasNext() {
            return pos.next != null;
        }

    public void next() {
            pos = pos.next;
        }

    public int value() {
            return pos.val;
        }
    }

public void addFirst(int v) {
        Node temp = new Node();
        temp.val = v;
        temp.next = head;
        if (head == null)
            head = tail = temp;
        else
            head = temp;
    }

public void addEnd(int v) {
        Node temp = new Node();
        temp.val = v;
        temp.next = null;
        if (head == null)
            head = tail = temp;
        else {
            tail.next = temp;
            tail = temp;
        }
    }

public void removeFirst() {
        if (head == null)
            return;
        if (head.next == null)
            head = tail = null;
        else
            head = head.next;
    }

public void removeEnd() {
        if (head == null)
            return;
        if (head.next == null) {
            head = tail = null;
            return;
        }
        Node p = head;
        for (; p.next.next != null; p = p.next)
            ;
        p.next = null;
        tail = p;
    }

public int size() {
        int cnt = 0;
        for (Node p = head; p != null; p = p.next)
            cnt++;
        return cnt;
    }

public void ADD_FRONT(int L, int step, int R) {
        for (int i = 0; L + i * step <= R; i++)
            addFirst(L + i * step);
    }

public void ADD_BACK(int L, int step, int R) {
        for (int i = 0; L + i * step <= R; i++)
            addEnd(L + i * step);
    }

public void REMOVE_FRONT(int iter) {
        for (; iter > 0; iter--)
            removeFirst();
    }

public void REMOVE_BACK(int iter) {
        for (; iter > 0; iter--)
            removeEnd();
    }

public void OUTPUT(LinkedList2 l) {
        for (Iterator i = new Iterator(l); i.hasNext(); i.next()) {
            System.out.print(i.value() + " ");
        }
        System.out.println();
    }

