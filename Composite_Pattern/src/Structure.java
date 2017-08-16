import java.util.ArrayList;
import java.util.List;

/**
 * Created by Xiaojun YU on 2017-08-09.
 */
public class Structure implements Group {
    private List<Group> groups = new ArrayList<Group>();


    @Override
    public void assemble() {
        for (Group group: groups) {
            group.assemble();
        }
    }
}
